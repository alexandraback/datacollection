easy_case = [1, 16, 50]
hard_case = [1, 32, 500]

from itertools import product

powers_memory = dict()
for i in range(2, 11):
    for k in range(0, 32):
        powers_memory[(i,k)] = i**k

cartesian_products = product([0,1], repeat=14)

def is_not_prime(n):
    for i in range(2, 10):
        if n%i == 0:
            return i
    return None

def read_base(bits, base, powers_memory):
    res = 0
    for i, bit in enumerate(bits):
        if bit == 1:
            res += powers_memory[(base, len(bits) - 1 - i)]
    return res

def solve(case, cartesian_products, powers_memory):
    number_of_bits = case[1]
    number_of_samples = case[2]
    res = []
    for partial_product in cartesian_products:
        candidate_product = [1] + list(partial_product) + [1]
        if len(res) == number_of_samples:
            return res
        else:
            aux = True
            divisors = []
            for base in range(2, 11):
                divisor = is_not_prime(read_base(candidate_product, base, powers_memory))
                if divisor:
                    divisors.append(divisor)
                else:
                    aux = False
                    break
            if aux:
                res.append((candidate_product, divisors))    
                
output_path = "C:/Users/paco/Dropbox/algorithms/google_jam/CoinJam/C-small.out"

with open(output_path, mode='w') as output:
    output.write("Case #1:\n")
    answer = solve(hard_case, cartesian_products, powers_memory)
    for product, divisors in answer:
        full_answer = ''.join([str(bit) for bit in product]) + ' ' + ' '.join([str(divisor) for divisor in divisors]) + '\n'
        output.write(full_answer)