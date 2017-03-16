
fin = open('luck.in')
fout = open('luck.out','w')
n_input = int(fin.readline())

primes = [2,3,5]
def factorize (n):
    d = {}
    for p in primes:
        d[p] = 0
        while n % p == 0:
            d[p] += 1
            n /= p
    return d

for i_input in range(n_input):
    temp = [ int(a) for a in fin.readline().split() ]
    R = temp[0]
    N = temp[1]
    M = temp[2]
    K = temp[3]

    fout.write("Case #" + str(i_input+1) + ":\n")
    for i_subinput in range(R):
        products = [ int(a) for a in fin.readline().split() ]
        factorizations = [factorize(n) for n in products]
        maxima = {p:max([f[p] for f in factorizations]) for p in primes}
        sums = {p:sum([f[p] for f in factorizations]) for p in primes}
        expsums = [sum([f[p] for p in f]) for f in factorizations]


        answer = {p:0 for p in primes}

        answer[3] = maxima[3]
        answer[5] = maxima[5]
        if 1 in [f[2]%2 for f in factorizations]:
            answer[2] = 1
        max_expsums = max(expsums)
        if max_expsums == 4:
            answer[4] = 1
        if max_expsums == 5:
            answer[4] = 2
        if max_expsums == 6:
            answer[4] = 3

        max_sums = max([sums[p] for p in sums])
        max_p = ([p for p in sums if sums[p]==max_sums])[0]
        answer[max_p] += 3 - sum([answer[p] for p in answer])

        answer_str = ""
        for p in answer:
            answer_str += str(p)*answer[p]
                
        
        
        fout.write(answer_str + "\n")
    



fin.close()
fout.close()
