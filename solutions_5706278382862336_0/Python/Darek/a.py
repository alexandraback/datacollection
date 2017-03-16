import math

def main():
    ifile = open('a.in', 'r')
    ofile = open('a.out', 'w')

    T = int(ifile.readline().strip())
    for case in range(1, T+1):
        p, q = (ifile.readline().strip()).rsplit('/')

        x = math.log(float(p), 2)
        y = math.log(float(q), 2)

        print(p, q, x, int(x), y, int(y))
        if y - int(y) != 0:
            print('Case #%d: impossible\n' %(case))
            ofile.write('Case #%d: impossible\n' %(case))
        else:
            res = int(y) - int(x)
            print('Case #%d: %d\n' %(case, res))
            ofile.write('Case #%d: %d\n' %(case, res))
        
        


        
        


        

if __name__ == "__main__":
    main()
