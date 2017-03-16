#!/usr/bin/python

def main():
    with open("A-small-attempt2.in") as f:
        T = int(f.readline().strip())

        for Tcur in range(1, T+1):
            line = ints(f.readline())[1:]
            
            print "Case #%d: " % Tcur,
            for Si in foo(line):
                print Si,
            print

        f.close()

def foo(nums):
    res = list()
    X = float(sum(nums))
    n = len(nums)
    tgt = 0
    
    plot = list(nums)
    for i in range(n):
        A = area(plot)
        if A > X:
            imax = 0
            for tmp in range(len(plot)):
                if plot[tmp] > plot[imax]:
                    imax = tmp
            plot.pop(imax)
        else:
            tgt = max(plot) + (X-A) / len(plot) 
            #print "Target is %d" % tgt
            break
    
    for i in range(n):
        if nums[i] > tgt:
            res.append(0.0)
        else:
            res.append(100.0 * (tgt - nums[i]) / X)
    return res

def area(plot):
    top = max(plot)
    a = 0
    for x in plot:
        a += (top - x)
    return a

def ints(astr):
    return [int(x) for x in astr.strip().split()]

if __name__=="__main__":
    main()
