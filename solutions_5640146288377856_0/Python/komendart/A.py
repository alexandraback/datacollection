def solve(fin):
    R, C, W = [int(i) for i in fin.readline().split()]
    result = C // W + W
    if C % W == 0:
        result -= 1
    return R * result

def main():
    with open("input.txt") as fin, open("output.txt", 'w') as fout:
        t = int(fin.readline())
        for i in range(1, t + 1):
            print("Case #{0}: {1}".format(i, solve(fin)), file=fout)
    
main()
