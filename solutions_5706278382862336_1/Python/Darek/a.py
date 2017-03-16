import math

def main():
    ifile = open('a.in', 'r')
    ofile = open('a.out', 'w')

    T = int(ifile.readline().strip())
    for case in range(1, T+1):
        p, q = [int(x) for x in (ifile.readline().strip()).rsplit('/')]

        f = int(q)
        while True:
            r = 2*(int(f/2)) - f
            if r == 0:
                f = int(f/2)
            else:
                break

        p = float(p / f)
        q = float(q / f)

        x = math.log(float(p), 2)
        y = math.log(float(q), 2)

        print(p, q, x, y, f)

        print(p, q, x, int(x), y, int(y))
        if y == 0 or y - int(y) != 0:
            print('Case #%d: impossible\n' %(case))
            ofile.write('Case #%d: impossible\n' %(case))
        else:
            res = int(y) - int(x)
            print('Case #%d: %d\n' %(case, res))
            ofile.write('Case #%d: %d\n' %(case, res))
        
        


        
        


        

if __name__ == "__main__":
    main()
