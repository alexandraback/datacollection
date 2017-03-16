EPSILON = 0.0000001

class Thing(object):
    def __init__(self,val,i):
        self.val = val
        self.i = i
        self.add = 0
        
    def __lt__(self,other):
        return self.val < other.val
    
    
class Thing2(object):
    def __init__(self,val,i):
        self.val = val
        self.i = i
        
    def __lt__(self,other):
        return self.i < other.i
    

def solve(s,z):
    m = z[-1].val
    for i in range(len(z)-1):
        x = z[i+1].val-z[i].val
        #print i,x
        if x*(i+1) > s:
            x = float(s)/(i+1)
        
        for j in range(i+1):
            z[j].add += x
        s -= x*(i+1)
        
        if s == 0:
            break
        '''x = min(s,m-z[i].val)
        z[i].add += x
        s -= x'''
        
    
    k = z[0].val + z[0].add
    count = 0
    for _ in z:
        if _.val + _.add == k:
            count += 1
            
    #for _ in z:
        #print _.val + _.add,
    #print ""
        
    rest = float(s)/count
    ans = []
    for j in range(len(z)):
        if z[j].val + z[j].add == k:
            z[j].add += rest
        ans.append(Thing2(z[j].add,z[j].i))
    ans.sort()
    #print ""
    return ans
    
    

data = open("P1.txt")
out = open("P1.out","w")
cases = int(data.readline())

for case in range(cases):
    info = map(int,data.readline().split())
    n = info[0]
    vals = info[1:]
    s = sum(vals)
    
    things = []
    for i in range(n):
        things.append(Thing(vals[i],i))
    things.sort()
    
    ans = solve(s,things)
    out.write("Case #%i: %.9f" %(case+1,ans[0].val/s*100))
    #print ans[0].val
    for z in ans[1:]:
        #print z.val
        out.write(" %.9f" %(z.val/s*100))
    out.write("\n")