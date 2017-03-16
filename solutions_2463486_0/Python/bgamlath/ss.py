def isPalin(n):
    return str(n) == str(n)[::-1]
    
def isFS(n):
    return isPalin(n) and isPalin(n*n)
    
a = ['0', '1', '2']
aa = ['00', '11', '22']

cc = 2;

res = [1, 2, 3, 11, 22]

for i in range(25): 
    cc += 1   
    t = []
    for b in a:
        t.append('0' + b + '0')
        for c in ['1', '2']:
            k = c + b + c
            if len(k) == cc and isFS(int(k)):
                t.append(str(k))
    for tt in t:
        if isFS(int(tt)): res.append(int(tt))
        #print tt
    a = t
    cc += 1   
    t = []
    for b in aa:
        t.append('0' + b + '0')
        for c in ['1', '2']:
            k = c + b + c
            if len(k) == cc and isFS(int(k)):
                t.append(str(k))
    for tt in t:
        if isFS(int(tt)): res.append(int(tt))
        #print tt;
    aa = t
    
res = [i*i for i in sorted(set(res))]

def proc(a, b, ss):
    i = 0; j =0;
    count = 0;
    while ss[i] < a:
        i += 1
    while(ss[i] >= a and ss[i] <= b):
        count += 1
        i += 1
        
    return count
    
fin = file('in.txt')
fout = file('out.txt','w')
first = True
n = 1
for line in fin:
    if not first:
        s = line.split(" ");
        print ("Case #%d: %d" % (n, proc(int(s[0]), int(s[1]), res)))
        n += 1;
    first = False
fin.close()
fout.close()
