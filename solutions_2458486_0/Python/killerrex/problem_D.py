#!/usr/bin/python3


def readint(fd):
    return [ int(x) for x in fd.readline().strip().split() ]


class Chest():
    def __init__(self, row, pos):
        self.pos = pos
        self.needs = row[0]
        self.loot = row[2:]
        self.isfree = self.needs in self.loot
    
    def __str__(self):
        return str(self.pos) + ": {" + str(self.needs) + "}" + str(self.loot)


class ChestGame():
    def __init__(self, fd):
        """
        Read from a file
        """
        K, N = readint(fd)

        # Read the starting keychain
        self.keys = readint(fd)
        
        # Read the chests
        self.chest = [None]*N
        for i in range(N):
            self.chest[i] = Chest(readint(fd), i+1)
        self.order = []

    def solve(self):
        # Maybe this is the last step
        if len(self.chest)==0:
            return True
        
        missing = list(chest.needs for chest in self.chest)
        while len(self.chest)>0:

            # Select a chest to open
            for i in range(len(self.chest)):
                chest = self.chest[i]
                # How many keys like this one we have
                n = self.keys.count(chest.needs)

                if n==0:
                    continue
                else:
                    # Choose the first one
                    p = self.keys.index(chest.needs)

                # Maybe nobody needs a key like this
                if chest.isfree or n>1 or missing.count(chest.needs)<=1:
                    # Ok open it
                    itsFree = True
                else:
                    # This is a no -return point
                    # Save current status
                    savepoint = [ list(missing), list(self.keys), list(self.chest), list(self.order)]
                    itsFree = False
                self.order.append(chest)
                del self.keys[p]
                del self.chest[i]
                # Missing array is in sync with chest array
                del missing[i]
                self.keys.extend(chest.loot)

                if itsFree or self.solve():
                    break
                else:
                    # Go Back
                    missing, self.keys, self.chest, self.order = savepoint
                    savepoint = None
            else:
                # We cannot open more chest! Fail
                return False
        return True

    def solution(self):
        if len(self.chest)>0:
            return "IMPOSSIBLE"
        else:
            return ' '.join(str(chest.pos) for chest in self.order)

    def __str__(self):
        """
        """
        s = "KEYS: " + str(self.keys)
        for c in self.chest:
            s += "\n  " + str(c)
        return s


def solve(fd):
    T = readint(fd)[0]
    for c in range(T):
        game = ChestGame(fd)
#        print(str(game))
        game.solve()
        print("Case #" + str(c+1) + ": " + game.solution())
        



if __name__ == "__main__":
    import sys
    
    fd = open(sys.argv[1], "r")
    solve(fd)
    fd.close()

            

