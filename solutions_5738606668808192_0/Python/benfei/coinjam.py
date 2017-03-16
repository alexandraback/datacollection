def coinjam_factory(n, j):
    r = n//2 - 2
    cj = list()
    for k in range(j):
        cj.append(coinjam_gen(k, r))
    
    return cj
        
    
def coinjam_gen(n, r):
    b = bin2(n, r)
    coin = "11" + "".join([l*2 for l in b]) + "11"
    proof = str(int(coin)//11)
    proofs = [str(int(proof, k)) for k in range(2,11)]
    return coin + " " + " ".join(proofs)
    
def bin2(n, r):
    b = bin(n)[2:]
    b = "0" * (r-len(b)) + b
    return b
    
def main():
    T = int(input())
    for t in range(1,T + 1):
        N, J = [int(x) for x in input().split(" ")]
        res = coinjam_factory(N, J)
        printable_res = "\n".join(res)
        print("Case #%d:\n%s" % (t, printable_res))
    
if __name__ == "__main__":
    main()