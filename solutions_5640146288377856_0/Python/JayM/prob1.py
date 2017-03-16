import sys
        
def func(r,c,w):
    if(c%w ==0):
        tmp=c/w
        return (r*tmp)+(w-1)
    else:
        tmp=c/w
        return (r*tmp)+w
if __name__=="__main__":
    fread=open(sys.argv[1],'r')
    total_case=fread.readline().strip()
    for case in range(int(total_case)):
        r,c,w=fread.readline().strip().split()
        #print r, c , w
        print "Case #{0}: {1}".format(case+1, func(int(r), int(c), int(w)) )
