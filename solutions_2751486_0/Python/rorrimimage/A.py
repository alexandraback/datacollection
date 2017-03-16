import sys,math
 
def readline_ints():
    return [int(num) for num in fin.readline().strip().split()]

def readline():
    return [num for num in fin.readline().strip().split()]

def splitstring(s):
    result = [s]
    for i in range(1, len(s)):
        result.extend('%s %s' % (s[:i], x) for x in splitstring(s[i:]))
    return result

##def consStr(name,n):
##    vowels = ['a','e','i','o','u']
##    consonents = ['b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z']
##    vals = [0 for j in range(len(name))]
##    for i in range(len(name)):
##        if name[i] not in vowels:
##            vals[i] = 1
##    start = []
##    nval = 0
##    for i in range(len(vals)-n+1):
##        start.append(i)
##        for j in range(n):
##            if vals[i+j]==0:
##                start.remove(i)
##                break
    
def consStr(name,n):
    n=int(n)
    vowels = ['a','e','i','o','u']
    consonents = ['b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z']
    vals = ""
    for i in range(len(name)):
        if name[i] in vowels:
            vals+="0"
        else:
            vals+="1"
    thing = "1" * n
    ans = 0
    for i in range(len(name)):
        for j in range(i,len(name)):
            if thing in vals[i:j+1]:
                ans+=1
    return ans
    
# <codecell>

# Update this with the filename
fname = "A-small-attempt1"
with open(fname+".in","r") as fin, open(fname+".out","w") as fout:

    numcases = readline_ints()[0]
    #print(numcases, "cases")
    
    for caseno in range(1, numcases+1):
        # Code goes here
        
        ran=readline()
        
        name=ran[0]
        n=ran[1]

        result = consStr(name,n)
        
        outstr = "Case #%d: %s" % (caseno, result)
        fout.write(outstr + "\n")
        print(outstr)
