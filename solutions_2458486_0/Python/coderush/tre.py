import re

class InvalidMoveException(Exception):
    pass

class Chest():
    def __init__(self,i,lock,keys):
        self.i = i
        self.lock = lock
        self.keys = keys

    def __eq__(self,other):
        return self.i == other.i

    def __repr__(self):
        return "Chest %d %s" % (self.lock, str(self.keys))

class Game():
    def __init__(self,keys,chests):
        self.keys = keys
        self.chests = chests

    def has_enough_keys(self):
        all_keys = list(self.keys)
        for c in self.chests:
            all_keys.extend(c.keys)
        if len(self.chests) > len(all_keys):
            return False
        return Game.can_open(all_keys,self.chests)

    @staticmethod
    def can_open(key_list,chest_list):
        key_list = list(key_list)
        for c in chest_list:
            if c.lock in key_list:
                key_list.remove(c.lock)
            else:
                return False
        return True

    def is_possible(self):
        if len(self.keys) == 0 or not self.has_enough_keys():
            #print "Not enough keys, only %s" % str(self.keys)
            return (False,0)
        if Game.can_open(self.keys,self.chests):
            return (True,[c.i for c in self.chests])
        key_chests = sorted([c for c in self.chests if c.keys != []],key=lambda c: c.i) 
        if len(key_chests) != len(self.chests):
            ngame = Game(self.keys,key_chests)
            print ("Trying subgame %s" % str(ngame))
            return ngame.is_possible()
        for c in self.chests:
            try:
                ngame = self.get_subgame(c)
                print ("Trying subgame %s" % str(ngame))
                tmp = ngame.is_possible()
                if tmp[0]:
                    print ("Subgame works! %d" % c.i)
                    tmp[1].insert(0,c.i)
                    return (True,tmp[1])
            except InvalidMoveException:
                pass
                print ("Can't open %s with only %s" % (str(c), str(self.keys)))
        print ("All subgames failed")
        return (False,0)


    def get_subgame(self,chest_used):
        if chest_used.lock not in self.keys:
            raise InvalidMoveException()
        keys = list(self.keys)
        if chest_used.lock not in keys:
            raise InvalidMoveException()
        keys.remove(chest_used.lock)
        keys.extend(chest_used.keys)
        chests = list(self.chests)
        chests.remove(chest_used)
        return Game(keys,chests)

    def __repr__(self):
        return "Game %s %s" % (str(self.keys), str(self.chests))

def check_game(g):
    print ("Trying with starting keys %s" % str(g.keys))
    result = g.is_possible()
    print (result)
    if not result[0]:
        return "IMPOSSIBLE"
    else:
        return " ".join([str(i) for i in result[1]])

def read_game(f):
    num_chests = int(re.split(" ",f.readline())[1].strip())
    keys = [int(x.strip()) for x in re.split(" ",f.readline())]
    chests = []
    for i in range(num_chests):
        raw = re.split(" ",f.readline())
        lock = int(raw[0])
        num_keys = int(raw[1].strip())
        c_keys = []
        for j in range(2,num_keys+2):
            c_keys.append(int(raw[j].strip()))
        chests.append(Chest(i+1,lock,c_keys))
    return Game(keys,chests)


def main():
    output = []
    with open("D-small-attempt0.in","r") as f:
        trials = f.readline()
        for i in range(int(trials.strip())):
            state = read_game(f)
            outline = "Case #%d: %s" % (i+1, check_game(state))
            print (outline)
            output.append(outline)
    with open("treasure.out","w") as f:
        f.write("\n".join(output))

def test_simple():
    c1 = Chest(1,2,[2,1])
    c2 = Chest(2,2,[])
    c3 = Chest(3,1,[])
    g1 = Game([2],[c1,c2,c3])
    g2 = g1.get_subgame(c2)
    print (g1)
    print (g2)
    assert g1.is_possible()
    assert not g2.is_possible()[0]

def test_chain():
    c1 = Chest(1,1,[2])
    c2 = Chest(2,2,[3])
    c3 = Chest(3,3,[4])
    c4 = Chest(4,4,[5,6])
    c5 = Chest(5,5,[1,1])
    c6 = Chest(6,5,[7])
    c7 = Chest(7,6,[5])
    c8 = Chest(8,7,[])
    cs = [c1,c2,c3,c4,c5,c6,c7,c8]
    g1 = Game([7],cs)
    g2 = Game([6],cs)
    g3 = Game([2],cs)
    assert not g1.is_possible()[0]
    result = g2.is_possible()
    print (result)
    assert result[0]
    result = g3.is_possible()
    print (result)
    assert result[0]

def test_advanced():
    c1 = Chest(1,1,[])
    c2 = Chest(2,2,[])
    c3 = Chest(3,3,[])
    c4 = Chest(4,1,[2,3])
    c5 = Chest(5,2,[])
    c6 = Chest(6,2,[2])
    c7 = Chest(7,3,[1])
    cs = [c1,c2,c3,c4,c5,c6,c7]
    g = Game([1,2,3],cs)
    result = g.is_possible()
    print (result)
    assert result[0]

if __name__ == "__main__":
    main()
