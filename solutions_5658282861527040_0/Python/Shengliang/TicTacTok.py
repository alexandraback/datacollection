def main():
    fin = file("B-small-attempt0.in","r")
    t = int(fin.readline())
    fout = file("B-small.out", "w")
    for i in range(t):
        scanf = fin.readline().split()
        a = int(scanf[0])
        b = int(scanf[1])
        k = int(scanf[2])
        counter = 0
        for first in range(a):
            for second in range(b):
                if (first & second < k):
                    counter += 1
        output = 'Case #' + str(i+1) + ": " + str(counter) + '\n'
        fout.write(output)

if __name__ == '__main__':
    main()
    
