from heapq import *

class Game(object):
    def __init__(self,a,b):
        self.lv1 = a
        self.lv2 = b
        self.done = 0
        
    def __lt__(self,other):
        '''if self.done == 2:
            return False
        if other.done == 2:
            return True'''
        if stars >= self.lv2: 
            return True
        if stars >= other.lv2:
            #not enough for self, but enough for other
            return False
        
        if self.done == 1:
            return False
        if other.done == 1:
            return True
        if stars >= self.lv1 and stars >= other.lv1:
            return self.lv2 > other.lv2
        if stars >= self.lv1:
            return True
        else:
            return False
        
    def __str__(self):
        return "(%i,%i)  %i" %(self.lv1,self.lv2,self.done)
        
     
def min(games):
    ret = 0
    for i in range(1,len(games)):
        if games[i] < games[ret]:
            ret = i
    return ret
    
'''stars = 5
a = Game(0,5)
a.done = 1
b = Game(4,7)
b.done = 0
print a < b'''

data = open("P2.txt")
cases = int(data.readline())
out = open("P2.out","w")

for case in range(cases):
    stars = 0
    n = int(data.readline())
    games = []
    for _ in range(n):
        a,b = map(int,data.readline().split())
        heappush(games,Game(a,b))
        
    ans = 0
    poss = True
    while len(games) > 0:
        ans += 1
        #top = heappop(games)
        #games.sort()
        #print min(games)
        #top = games.pop(0)
        i = min(games)
        top = games.pop(i)
        #print top,stars
        
        if stars >= top.lv2:
            stars += 2-top.done
            
        elif stars >= top.lv1:
            if top.done == 1:
                poss = False
                break
            else:
                top.done = 1
                stars += 1
                #heappush(games,top)
                games.append(top)
        else:
            poss = False
            break
        
    #print poss
    if not poss:
        ans = "Too Bad"
    out.write("Case #%i: %s\n" %(case+1,ans))
    print "Case #%i: %s" %(case+1,ans)
    #print "\n"