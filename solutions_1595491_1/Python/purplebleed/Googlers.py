
def estimate(num):
    if num == 0:
        return [0,0]
    elif num == 1:
        return [1,1]
    elif num == 29:
        return [10,10]
    elif num == 30:
        return [10,10]
    m = num %3
    base = num/3
    if m == 0:
        return [base+1,base]
    elif m == 1:
        return [base+1,base+1]
    elif m == 2:
        return [base+2,base+1]

def main():
    
    
    f = open('./test2', 'r')
    w = open('./out2.txt','w')
    count = int(f.readline())
    for i in range(0,count):
        l = f.readline().split(' ')
        t = int(l[0])
        sup_count = int(l[1])
        high = int(l[2])
        maxs = 0
        maxu = 0
        scores = []
        for j in range(0,t):
            scores.append(int(l[j+3]))
        
        for s in scores:
            sup,unsup = estimate(s)
            if sup >= high:
                maxs += 1
            if unsup >= high:
                maxu += 1
        ans = min(maxs,maxu+sup_count)
        print "Case #%d: %d" %(i+1,ans)
        w.write("Case #%d: %d\n" %(i+1,ans))
    
main()