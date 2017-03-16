'''
Created on 2012-4-28

@author: mzh.li
'''

if __name__ == '__main__':
    
    with open("A-large.in", 'r') as fi, open("A-large.out", "w") as fo:
        T = int(fi.readline())
        for t in range(0,T):
            l = [int(i) for i in fi.readline().split()]
            pl = [float(i) for i in fi.readline().split()]
            for i in range(1,len(pl)):
                pl[i] *= pl[i - 1]
            
            minstep = l[1] + 2
            
            for i in range(len(pl), 0, -1):
                temp =  (len(pl) - i + l[1] - i + 1) + (1 - pl[i - 1]) * (l[1] + 1)
                if temp < minstep:
                    minstep = temp
            #print "Case #%d: %.6f"%(i, minstep)
            fo.write("Case #%d: %.6f\n"%(t + 1, minstep))
 