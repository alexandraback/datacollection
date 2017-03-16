def main():
    i = open('b2.txt', 'r')
    o = open('b2.out', 'w')

    n = int(i.readline().split()[0])

    for k in range(1, n+1):
        c, f, x = [float(x) for x in i.readline().split()]
        r = c / f

        t, cookies, growth = 0, 0, 2

        while (True):
            if cookies + growth * r >= x:
                t = t + (x - cookies) / growth
                break
            if cookies >= c:
                cookies = cookies - c
                growth = growth + f
            else:
                t = t + (c - cookies) / growth
                cookies = c
        o.write('Case #%d: %.7f\n' %(k, t))
                
        

if __name__ == "__main__":
    main()
