import sys
import string
import math

def main():
    results = coin(int(sys.argv[1]), int(sys.argv[2]))
    print("N is {0} and J is {1}".format(sys.argv[1], sys.argv[2]))
    # inF = open(sys.argv[1], 'r')
    name = 'coins' # string.split(sys.argv[1], '.', 1)[0]
    ouF = open("{0}.out".format(name), 'w')
    # T = int(inF.readline())
    # for i in range(T):
    #     K, C, S = tuple(map(int, inF.readline().split(' ')))
    #     # print(K,C,S)
    #     k = fractile(K, C, S)
    #     if k == None:
    #         k = "IMPOSSIBLE"
    #         ouF.write("Case #{0}: {1}\n".format(i+1, k))
    #     else:
    #         ouF.write("Case #{0}:".format(i+1))
    #         for n in k:
    #             ouF.write(" {0}".format(n))
    #         ouF.write("\n")
    # inF.close()
    ouF.write("Case #1:\n")
    for result in results:
        ouF.write("{0}".format(result[0]))
        for n in result[1]:
            ouF.write(" {0}".format(n))
        ouF.write("\n")
    ouF.close()

def coin(N, J):
    num = "1{0}1".format('0'*(N-2))
    # end = '1'*N

    results = []
    while len(results) < J:
        print(num)
        divisors = []
        for i in range(2,11):
            based = int(num, i)
            d = divisor(based)
            if d == None:
                break
            divisors.append(d)
        if len(divisors) == 9:
            results.append([num, divisors])
        num = str(bin(int(num,2)+2)[2:])
    return results


def divisor(n):
    for i in range(2, int(n**.5)):
        if n % i == 0:
            return i
    return None


if __name__ == '__main__':
  main()
