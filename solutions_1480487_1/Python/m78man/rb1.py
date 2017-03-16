


def main():
    inpfile = open("A-large.in", 'r')
    outfile = open('outfile', 'w')
    casenum = int(inpfile.readline().strip())
    for case in range(1, casenum + 1):
        line = inpfile.readline().strip()

        linelst = line.split()

        n = int(linelst[0])
        
        linelst = linelst[1:]
        
        x = 0
        for i in linelst:
            x += int(i)
        
        #print x
        
        
        x2 = x * 2
        
        #print x2
        
        x3 = x2 / float(n)
        
        for i in linelst:
            j = int(i)
            if (j > x3):
                x2 -= j
                n -= 1
                
        x3 = x2 / float(n)
        
        #print x2
        #print x3
        
        r = ""
        
        
        
        for i in linelst:
            d = x3 - int(i)
            p = max(d / x, 0.0)
            #print p
            r += str(p * 100)
            r += " "
            
        r = r[:-1]
        #print r


        result = "Case #" + str(case) + ": " + str(r)+"\n"
        print result
        outfile.write(result)
    inpfile.close()
    outfile.close()




if __name__ == "__main__":
    main()
    
    
    