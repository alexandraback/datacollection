import sys

pattern = "Case #{0}: {1}"

class GeneralException(Exception):
    def __init__(self):
        super(self,GeneralException).__init__()

class GameOver(Exception):
    def __init__(self):
        super(self,GameOver).__init__()


class Game:
    
    def __init__(self,n_l,k_l):
        self._n_l = n_l
        self._k_l = k_l
        self._n_l.sort()
        self._k_l.sort()
        self._forcheat = []
        self._last_k = 0
        self.init_cheat()

    def init_cheat(self):
        self._forcheat = [(i,True) for i in self._n_l]+[(j,False) for j in self._k_l]
        self._forcheat.sort()
        for i in xrange(len(self._forcheat)-1,-1,-1):
            if not self._forcheat[i][1]:
                self._last_k = i
                break

    def play_fair(self):
        point = 0
        index_k = 0
        n_l = self._n_l[:]
        k_l = self._k_l[:]
        while n_l[0] < k_l[-1]:
            while k_l[index_k] < n_l[0]:
                index_k += 1
                if index_k == len(k_l):
                    return len(n_l)
            while n_l[0] < k_l[index_k]:
                n_l.pop(0)
                k_l.pop(index_k)
                index_k = min(index_k,len(k_l)-1)
                if not k_l:
                    return 0

        assert(len(n_l) == len(k_l))
        return len(n_l)

    def update_cheat(self):
        if self._last_k < 0:
            raise GeneralException()

        for i in xrange(min(self._last_k,len(self._forcheat)-1),-1,-1):
            if not self._forcheat[i][1]:
                self._last_k = i
                break

    def consolidate(self):
        while self._forcheat[0][1]:
            self._forcheat.pop(self._last_k)
            self._forcheat.pop(0)
            if not self._forcheat:  
               break
            self._last_k -= 2
            self.update_cheat()

    def count_point(self):
        counter = 0
        point = 0
        last_index = 0

        if not self._forcheat:
            return 0
        for last_index,v in enumerate(self._forcheat):
            counter += (-1)**v[1]
            if not v[1]:
                point += 1
            if not counter:
                break
        self._forcheat = self._forcheat[last_index+1:]
        if self._forcheat:
            self.update_cheat()
        return point
    
    def cheat(self):
        point = 0
        while self._forcheat:
            self.consolidate()
            point += self.count_point()
        return point


def play(f):
    f.readline()
    nl = map(float,f.readline().rstrip("\n").split())
    kl = map(float,f.readline().rstrip("\n").split())
    game = Game(nl,kl)
    fair = game.play_fair()
    c =  game.cheat()
    return c, fair

if __name__=="__main__":
    with open(sys.argv[1]) as f:
        ntests = int(f.readline())
        for i in xrange(1,ntests+1):
            result = play(f)
            print pattern.format(str(i)," ".join(map(str,result)))

