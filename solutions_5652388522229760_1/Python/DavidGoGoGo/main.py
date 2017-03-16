def countSheep(num):
    if num == 0:
        return "INSOMNIA"
    count = 1
    fullSet = {'1','2','3','4','5','6','7','8','9','0'}
    digitSet = set()
    while(1):
        for char in str(count * num):
            digitSet.add(char)
        if fullSet == digitSet:
            return count * num
        count +=1
    return

def main():
    infile = open('input.in')
    t = int(infile.readline())
    f = open('problem_1_res.output', 'w')
    for i in range(1, t+1):
        n = int(infile.readline())
        res = countSheep(n)
        f.write("Case #{}: {}\n".format(i, res))
    f.close()
    infile.close()
main()