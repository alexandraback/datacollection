#fi=open("B-large.in"); fo=open("B-large.out","w")
fi=open("B-small-attempt0.in"); fo=open("B-small-attempt0.out","w")

def calc(s):
    t=[s[0]]    
    for x in s[1:]: 
        if x!=t[-1]: t.append(x)
    if t[-1]=='+': t.pop()    
    return len(t)

for T in range(int(fi.readline())):     
    print("Case #"+str(T+1)+":",calc(fi.readline().strip()),file=fo)

fi.close()
fo.close()
print("OK")