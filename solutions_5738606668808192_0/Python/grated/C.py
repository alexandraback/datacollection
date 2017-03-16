# coding: utf-8

import math

prime = list()

def make_binary(n, mask):
    length, binary = n - 2, list()
    #import pdb; pdb.set_trace()
    for i in xrange(length - 1, -1, -1):
        if (mask & (1 << (i))):
            binary.append("1")
        else:
            binary.append("0")
    return binary

def cal(n, binary, base):
    s, mul = 1, base
    for bit in binary[::-1]:
        if bit == "1":
            s += mul
        mul *= base
    s += mul
    
    for p in prime:
        if s % p == 0:
            print "%s: %s %s" % (base, s, p)
            return p
            
    #mid = int(math.sqrt(s + 0.5))
    #for div in xrange(2, mid + 1):
    #    if s % div == 0:
    #        print "%s: %s %s" % (base, s, div)
    #        return div
    print "%s: %s ###" % (base, s)
    return 0

def run(input_path, output_path):
    with open(output_path, "wb") as fout:
        with open(input_path, "r") as fin:
            T = int(fin.readline().rstrip())
            line = map(lambda x: int(x), fin.readline().split())
            n, m = line[0], line[1]
        
        for t in xrange(1, T + 1):
            out = "Case #%s:" % t
            print out
            fout.write("%s\n" % out)

            limit, counter = 1 << (n - 2), 0
            for mask in xrange(0, limit):
                binary = make_binary(n, mask)
                print mask, binary
                diviors = list()
                for base in xrange(2, 11):
                    div = cal(n, binary, base)
                    if not div:
                        break
                    else:
                        diviors.append(div)
                else:
                    diviors = map(lambda x: str(x), diviors)
                    out = "1%s1 %s" % (''.join(binary), ' '.join(diviors))
                    fout.write("%s\n" % out)
                    print out
                    counter += 1
                
                if counter >= m: break

def get_prime():
    limit = 10000010
    vis = [0 for _ in range(limit)]
    for i in xrange(2, limit):
        if not vis[i]:
            prime.append(i)
            for j in xrange(i+i, limit, i):
                vis[j] = 1
    #print prime
if __name__ == "__main__":
    get_prime()
    #run("small_c_in.txt", "small_c_out.txt")
    run("large_c_in.txt", "large_c_out.txt")
