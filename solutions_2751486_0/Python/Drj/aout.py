vowels = ['a','e','i','o','u']
f = open('a.txt')
g = open('aout.txt','w')
def test(s,n):
    global vowels
    count = 0
    for i in s:
        if i not in vowels:
            count+=1
            if count>=n:
                return 1
        else:
            count = 0
    if count>=n:
        return 1
    else:
        return 0
    
def fun(st,n):
    i = n
    j = 0
    l = 0
    while i<len(st):
        for j in range(0,len(st)-i+1):
            l+=test(st[j:j+i],n)
            #print test(st[j:j+i],n),st[j:j+i]
        i+=1
    l+=test(st,n)
    return l
            
c = "Case #"
x = int(f.readline())

for i in range(x):
    s = f.readline().split()
    st = s[0]
    n = int(s[1])
    z = fun(st,n)
    g.write(c+str(i+1)+": "+str(z)+"\n")
f.close()
g.close()
