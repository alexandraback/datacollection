

def output(t, res):
    casestr = "Case #" + str(t+1) +": "
    status = str(res) if res != None else "IMPOSSIBLE"
    outputLine = casestr+status
    print outputLine




def main():


    ############################################1
    T = int( raw_input() )
    for t in xrange(T):    
        B, M = map(int, raw_input().split())

        maxSlides = B*(B-1)/2
        maxM = 2**(B-2)
        if M > maxM:
            output(t, None)
            continue
        if M == maxM:
            line1 = '0' + '1'*(B-1)
        else:
            Mbin = "{0:b}".format(M)
            line1 = Mbin + '0'
            line1 = line1.zfill(B)
            #print 't=' + str(t) + ' line1=' + line1, M, maxM
        matrix = [line1]
        for i in xrange(1,B):
            matrix.append( ('1'*(B-i-1)).zfill(B) )
        output(t, "POSSIBLE\n" + "\n".join(matrix))        



if __name__ == "__main__":
   main()