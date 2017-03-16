class Tribe:
    def __init__(self, di, ni, wi, ei, si, delta_di, delta_pi, delta_s):
        self.di = di
        self.ni = ni
        self.wi = wi
        self.ei = ei
        self.si = si
        self.delta_di = delta_di
        self.delta_pi = delta_pi
        self.delta_s = delta_s
        self.attacks_passed = 0
    
    def get_next_attack(self, day):
        self.attacks_passed += 1
        if self.attacks_passed == 1:
            return self.wi, self.ei, self.si
        else:
            wi = self.wi + self.delta_pi * (self.attacks_passed - 1)
            ei = self.ei + self.delta_pi * (self.attacks_passed - 1)
            si = self.si + self.delta_s * (self.attacks_passed - 1)
            return wi, ei, si
    
    def check_next_day(self):
        if self.attacks_passed == 0:
            return self.di
        elif self.attacks_passed >= self.ni:
            return 67606000
        else:
            return self.di + self.attacks_passed * self.delta_di
            

import sys
T = int(sys.stdin.readline())
for case in xrange(1, T+1):
    N = int(sys.stdin.readline())
    tribes = []
    for _ in xrange(N):
        [di, ni, wi, ei, si, delta_di, delta_pi, delta_si] = map(int, sys.stdin.readline().split())
        tribes.append(Tribe(di, ni, wi, ei, si, delta_di, delta_pi, delta_si))
    
    res = 0
    wall = {}
    i = -300
    while i <= 300:
        wall[i] = 0
        i += 0.5
    
    while True:
        l = []
        min_v = 67606000
        for t in tribes:
            v = t.check_next_day()
            l.append(v)
            min_v = min(min_v, v)
        if min_v == 67606000:
            break
        #print "->min_v:", min_v
        
        new_wall = {}
        for i, t in enumerate(tribes):
            if l[i] == min_v:
                #print "tribe:", i
                wi, ei, si = t.get_next_attack(min_v)
                #print (wi, ei, si)
                succ = False
                #for i in range(wi, ei+1):
                i = wi
                while i <= ei:
                    if wall[i] < si:
                        new_wall[i] = si
                        succ = True
                    i += 0.5
                if succ:
                    #print "success!"
                    res += 1
        for k, v in new_wall.iteritems():
            wall[k] = v
            
    
    print "Case #"+str(case)+": "+str(res)
