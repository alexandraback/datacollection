def main():
    fin = file("D-small-attempt0.in","r")
    t = int(fin.readline())
    fout = file("D-small.out", "w")
    for i in range(t):
        n = int(fin.readline())
        scanf = fin.readline().split()
        a = []
        for j in scanf:
            a.append(float(j))
        a.sort();
        
        scanf = fin.readline().split()
        b = []
        for j in scanf:
            b.append(float(j))
        b.sort()
        awar = a[:]
        bwar = b[:]
        war = 0
        for x in awar:
            for y in bwar:
                if y > x:
                    break
            if y > x:
                bwar.remove(y)
            else:
                bwar.remove(bwar[0])
                war = war + 1
        a.reverse()
        b.reverse()
        dec_war = 0
        while(len(b) > 0):
            if a[0] > b[0]:
                dec_war = dec_war + 1
                a.remove(a[0])
            b.remove(b[0])

        output = "Case #" + str(i+1) + ": " + str(dec_war) + " " + str(war) + '\n'
        fout.write(output)
        
if __name__ == '__main__':
    main()
