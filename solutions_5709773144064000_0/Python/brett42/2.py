def go():
    f=open('in.txt')
    c=int(f.readline())
    for case in range(1,c+1):
        r=[float(x) for x in f.readline().split()]
        print 'Case #%d:'%case,solve(r[0],r[1],r[2])
    f.close()

def solve(cost,drate,goal):
    rate=2.0
    plustime=0
    while 1:
        time=goal/rate+plustime
        newrate=rate+drate
        plustime+=cost/rate
        newtime=goal/newrate+plustime
        rate=newrate
        if newtime>time:
            return time
        
    
    
