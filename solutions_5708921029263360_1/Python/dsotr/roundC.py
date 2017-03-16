import time


def solve_case(in_data):
    (J,P,S,K) = [int(x) for x in in_data]
    print((J,P,S,K))
    result = ""
    y = 0
    startp = 0
    starts = 0
    for j in range(J):
        k = min(S, K)
        while k > 0:
            for p in range(P):
                result += "%i %i %i\n" % (j+1, ((p+startp) % P)+1, ((starts+p) % S)+1)
                y += 1
            starts += 1
            k -= 1
        startp += 1
        starts = 0
    return str(y) + "\n" + result

if __name__ == '__main__':
    start = time.time()
    path = './C-large.in'
    #path = './A-large.in'
    out = open(path + '.out', 'w', newline='')
    count = 1
    with open(path) as f:
        T = int(f.readline().strip())
        for i in range(T):
            print(count)
            out.write("Case #%i: %s" % (count, solve_case(f.readline().strip().split(" "))))
            count += 1
    out.close()
    print("Elapsed: %f seconds" % (time.time() - start))
