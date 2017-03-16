import sys

def main():
    f = open(sys.argv[1], "r")
    t = int(f.readline().strip())

    f2 = open(sys.argv[2], "w")

    for i in range(t):
        f2.write("Case #"+str(i+1)+": ")
        line = f.readline().strip().split()

        a = int(line[0])
        b = int(line[1])
        k = int(line[2])

        res = [0]*k

        for m in range(a):
            for n in range(b):
                c = m & n
                if c < k:
                    res[c] += 1

        f2.write(str(sum(res)))
        
        f2.write("\n")

if __name__ == "__main__":
    main()
    
