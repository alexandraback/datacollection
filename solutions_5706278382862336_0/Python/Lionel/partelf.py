import sys

def main():
    f = open(sys.argv[1], "r")
    t = int(f.readline().strip())

    f2 = open(sys.argv[2], "w")

    for i in range(t):
        f2.write("Case #"+str(i+1)+": ")
        line = f.readline().strip().split("/")

        a = long(line[0])
        b = long(line[1])

        ind = 0

        while b >= 1:
            if b % 2 != 0:
                break
            else:
                b /= 2
                ind += 1

        if a % b != 0:
            f2.write("impossible\n")
            continue
        else:
            a /= b

        res = 1
        tmp = long(pow(2,ind-1))

        while a < tmp:
            tmp /= 2
            res += 1

        f2.write(str(res))
        
        f2.write("\n")

if __name__ == "__main__":
    main()
