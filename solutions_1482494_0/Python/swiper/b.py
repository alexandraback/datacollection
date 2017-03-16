class Solver:
    def __init__(self, s, require):
        #print s
        self.s = s
        self.require = require
        self.N = len(require)
        self.solved = [[False, False] for i in range(N)]
        self.two_star_min_level = 0
        self.one_star_min_level = 0
        self.current_star = 0
        self.total = 0
        self.unsolved = N

    def find_two_star(self):
        #print "In find two star"
        while self.two_star_min_level <= self.current_star:
            for k in self.s[self.two_star_min_level]:
                if k[1] == 2:
                    #print "solved level:", k
                    self.s[self.two_star_min_level].remove(k)
                    l = k[0]
                    # solve level k staring game
                    self.solved[l][1] = True
                    if self.solved[l][0]:
                        self.current_star += 1
                    else:
                        self.current_star += 2
                        # remove the 1 star game for this level
                        r = self.require[l][0]
                        self.s[r].remove((l, 1))
                        # mark the 1 star game as solved
                        self.solved[l][0] = True
                    #print "Current_star =", self.current_star
                    return True
            self.two_star_min_level += 1
        return False
    
    def find_one_star(self):
        #print "In find one star"
        while self.one_star_min_level <= min(self.N, self.current_star) and len(self.s[self.one_star_min_level]) == 0:
            self.one_star_min_level += 1
        if self.one_star_min_level > min(self.N, self.current_star):
            return False
        else:
            l, star = self.s[self.one_star_min_level].pop()
            #print "Solved level:", (l, star)
            # solve the 1 staring game for level l
            self.solved[l][0] = True
            self.current_star += 1
            #print "current star =", self.current_star
            return True

    def solve(self):
        while self.unsolved > 0:
            while self.unsolved > 0 and self.find_two_star():
                self.total += 1
                self.unsolved -= 1
            if self.unsolved > 0 and self.find_one_star():
                self.total += 1
            elif self.unsolved > 0:
                return "Too Bad"
        return self.total
    

def build_req_table(require, N):
    s = [set() for i in range(2*N)]    
    for l in range(N):
        for star in range(2):
            r = require[l][star]
            if r < 2*N:
                s[r].add((l, star+1))
            else:
                return -1
    return s

T = int(raw_input())

for t in range(1, T+1):
    N = int(raw_input())
    require = [map(int, raw_input().split()) for i in range(N)]

    requ_table = build_req_table(require, N)
    if requ_table == -1:
        print "Case #%d: Too Bad" % t
        continue
    else:
        solver = Solver(requ_table, require)
        print "Case #%d: %s" % (t, str(solver.solve()))
