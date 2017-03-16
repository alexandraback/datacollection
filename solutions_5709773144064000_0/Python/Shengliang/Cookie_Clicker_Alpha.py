def main():
    fin = file("B-small-attempt0.in","r")
    t = int(fin.readline())
    fout = file("B-small.out", "w")
    for i in range(t):
        scanf = fin.readline().split()
        c = float(scanf[0])
        f = float(scanf[1])
        x = float(scanf[2])
        time = 0.0
        s = 2
        while True:
            if x/(s + f) < (x - c)/s:
                time = time + c / s
                s = s + f
            else:
                time = time + x / s
                break
        output =  "Case #" + str(i + 1) + ": " + str(time) + '\n'
        fout.write(output)

if __name__ == '__main__':
    main()
