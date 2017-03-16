'''OMFG just wasted an hour debugging my incorrect solution because I didn't notice the
"No triplet of scores contains scores that are more than 2 apart."
'''

def is_sur(a,b,c):
    return abs(a-b) >= 2 or abs(a-c) >= 2 or abs(b-c) >= 2

def is_ok(a,b,c):
    return abs(a-b) <= 2 and abs(a-c) <= 2 and abs(b-c) <= 2

sur = [[0]*31 for z in range(11)]
for p in range(11):
    for a in range(11):
        for b in range(11):
            for c in range(11):
                if is_ok(a,b,c) and max(a,b,c) >= p:
                    if is_sur(a,b,c):
                        sur[p][a+b+c] = max(sur[p][a+b+c],1)
                    else:
                        sur[p][a+b+c] = max(sur[p][a+b+c],2)
  
'''print "  ",
for i in range(31):
    if len(str(i)) == 1:
        print "%i " %(i),
    else:
        print "%i" %(i),
print ""
for i in range(11):
    print i,sur[i]'''
    
data = open("dancing_with_googlers.in")
out = open("dancing_with_googlers.out","w")
cases = int(data.readline())

for case in range(cases):
    info = map(int,data.readline().split())
    n,s,p = info[:3]
    info = info[3:]
                        
    count = 0
    for num in info:
        if sur[p][num] == 2: count += 1
        
    for num in info:
        if s <= 0: break
        if sur[p][num] == 1: 
            count += 1
            s -= 1
        
    out.write("Case #%i: %i\n" %(case+1,count))