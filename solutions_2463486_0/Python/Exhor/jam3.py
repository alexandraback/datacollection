import time, string

t = time.time();
f = open('C-small-attempt0.in','r')
fout = open('output.txt','w')
ncases = int(f.readline())
for i in range(ncases):
    nl = f.readline()
    nl = nl.replace('\\', '').replace('n',''); #remove the "\n"
    AB = string.split(nl, ' ')
    A = int(AB[0])
    B = int(AB[1])
    sqA = int((A-1)**0.5) + 1
    sqB = int((B)**0.5)
    c = 0
    m = int(len(str(sqA)) / 2)
    n = int(len(str(sqB)) / 2)
    for candtail in xrange(10**n+1):
        for middlenumber in ['','0','1','2','3','4','5','6','7','8','9']:
            cand = int( str(candtail) + middlenumber + str(candtail)[::-1])
            if candtail == 0:
                if middlenumber == '':
                    cand = 0
                else:
                    cand = int(middlenumber)

            if (cand >= sqA and cand <= sqB):
                sq = str( cand ** 2 )
                sqback = sq[::-1]
                # check if palindrome
                ispal = (sq == sqback);
                if ispal:
                    c = c + 1;

    casedesc = 'Case #' + str(i+1) + ': ' + str(c) + '\n'
    fout.write( casedesc )

fout.close()
f.close()
print "Time per case:", (time.time() - t) / ncases

