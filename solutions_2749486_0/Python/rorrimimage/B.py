import sys,math

def readline_ints():
    return [int(num) for num in fin.readline().strip().split()]

# <codecell>

# Update this with the filename
fname = "B-small-attempt0"
with open(fname+".in","r") as fin, open(fname+".out","w") as fout:

    numcases = readline_ints()[0]
    #print(numcases, "cases")
    
    for caseno in range(1, numcases+1):
        # Code goes here
        
        ran=readline_ints()
        
        x=ran[0]
        y=ran[1]

        result=""
        jump=1
        
        if x<0:
            for i in range(-x):
                result+="EW"
                jump+=2
        if x>0:
            for i in range(x):
                result+="WE"
                jump+=2
        if y<0:
            for i in range(-y):
                result+="NS"
                jump+=2
        if y>0:
            for i in range(y):
                result+="SN"
                jump+=2

        outstr = "Case #%d: %s" % (caseno, result)
        fout.write(outstr + "\n")
        print(outstr)

