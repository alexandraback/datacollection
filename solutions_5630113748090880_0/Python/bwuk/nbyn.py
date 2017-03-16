#nByn


def main():
    f = open("nbyn.in", "r")
    numCases = int(f.readline())

    for i in range(1, numCases+1):
        n = int(f.readline())

        result = []
        for j in range(0, 2 * n - 1):
            line = f.readline().strip().split(' ')

            for k in line:
                k = int(k)
                if k in result:
                    result.remove(k)
                else:
                    result.append(k)

        result.sort()
        
        print("Case #", i, ": ", ' '.join(map(str,result)), sep='')

main()        
