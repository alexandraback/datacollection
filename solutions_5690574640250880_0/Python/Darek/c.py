def main():
    ifile = open('c.txt', 'r')
    ofile = open('c.out', 'w')

    T = int(ifile.readline().split()[0])

    for case in range(1, T+1):

        r, c, m = [int(x) for x in ifile.readline().split()]
        b = r*c - m
        found = False
        ofile.write('Case #%d:\n' %case)

        if b == 1:
            found = True
            h = w = 1
            e = e2 = 0
            
        if r == 1:
            found = True
            h, w = 1, b
            e = e2 = 0
            
        limit = int(min(b-1, r))
        for i in range(2, limit+1):
            if (found):
                break
            h, w = i, b/i
            e = b%i
#            ofile.write('%d %d %d\n' %(h, w, e))
            if (2 <= w <= c and e==0):
                found = True
                e = e2 = 0
            elif(2 <= w <c):
                if (e >= 2):
#                    ofile.write('Here: %d %d %d\n' %(h, w, e))
                    found = True
                    e2 = 0
                elif (w >=3 and h>= 3):
                    found = True
                    w = w-1
                    e, e2 = h-1, 2
                        
        if found:
 #           ofile.write('%d %d %d %d\n' %(b, h, w, e))    
            for j in range(0, r):
                for k in range (0, c):
                    if j == k == 0:
                        ofile.write('c')
                    elif (j< h and k < w):
                        ofile.write('.')
                    elif (k == w and j <e):
                        ofile.write('.')
                    elif (k == w+1 and j< e2):
                        ofile.write('.')
                    else:
                        ofile.write('*')
                ofile.write('\n') 
            continue


        if c == 1:
            found = True
            h, w = b, 1
            e = e2 = 0
            
        limit = int(min(b-1, c))
        for i in range(2, limit+1):
            if (found):
                break
            w, h = i, b/i
            e = b%w
#            ofile.write('Next: %d %d %d\n' %(h, w, e))
            if (2<= h <=r and e==0):
                found = True
                e = e2 = 0
            elif(2 <= h < r):
                if (e>=2):
                    found = True
                    e2 = 0
                elif (w >=3 and h>= 3):
                    found = True
                    h = h-1
                    e, e2 = w-1, 2
                    
        if found:
#            ofile.write('%d %d %d %d\n' %(b, h, w, e))   
            for j in range(0, r):
                for k in range (0, c):
                    if j == k == 0:
                        ofile.write('c')
                    elif (j< h and k < w):
                        ofile.write('.')
                    elif (j == h and k <e):
                        ofile.write('.')
                    elif (j == h+1 and k <e2):
                        ofile.write('.')
                    else:
                        ofile.write('*')
                ofile.write('\n')
        else:
            ofile.write('Impossible\n')                
        

if __name__ == "__main__":
    main()
