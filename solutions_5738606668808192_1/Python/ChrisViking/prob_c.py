__author__ = 'Christian'
import math, itertools

#fname = 'test_c.txt'
#fname = 'C-small-attempt1.in'
fname = 'C-large.in'

res_file = open(fname + '.res', 'w')

# I first loaded a list of 2 million prime numbers, extracted the proper number of results
# then limited the list to only the prime I used.

## load primes
#prime_list = []

#f = open('full_prime.txt', 'r')
#for p in f:
    #prime_list.append(int(p.strip('\n').strip('\r')))
#f.close()

prime_list = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 337, 347, 349, 353, 359, 367, 373, 379, 383, 397, 401, 409, 419, 421, 431, 439, 443, 449, 457, 467, 479, 491, 499, 503, 509, 523, 541, 557, 563, 569, 571, 577, 593, 599, 607, 617, 643, 647, 677, 701, 709, 719, 739, 743, 797, 811, 823, 827, 829, 859, 877, 883, 911, 919, 937, 941, 953, 991, 1009, 1061, 1063, 1091, 1093, 1097, 1163, 1193, 1213, 1217, 1223, 1229, 1237, 1277, 1283, 1297, 1429, 1433, 1451, 1453, 1489, 1523, 1553, 1567, 1579, 1601, 1637, 1697, 1699, 1747, 1811, 1847, 1871, 1877, 1889, 1901, 1949, 1997, 2029, 2053, 2069, 2083, 2087, 2129, 2141, 2143, 2239, 2251, 2273, 2309, 2399, 2459, 2593, 2609, 2621, 2633, 2689, 2801, 2819, 2837, 2879, 2897, 2969, 3011, 3041, 3187, 3209, 3301, 3593, 3719, 3739, 3761, 3823, 3851, 3989, 4013, 4019, 4129, 4153, 4441, 4507, 4517, 4603, 4813, 5039, 5099, 5237, 5273, 5443, 5503, 5701, 5879, 5953, 6043, 6481, 6793, 6863, 6997, 7103, 7187, 7207, 7393, 7487, 7753, 7949, 8123, 8293, 8329, 8963, 8969, 8971, 9719, 9901, 9923, 10781, 11149, 11621, 11959, 12379, 13109, 13337, 13417, 13591, 14519, 14891, 15149, 16319, 16567, 16699, 16879, 17047, 18443, 18521, 18587, 18691, 18899, 18959, 19531, 19739, 19793, 20521, 21649, 22037, 22273, 23039, 23369, 23531, 26683, 27509, 27851, 28387, 29147, 29153, 29537, 30169, 30763, 31477, 32251, 32359, 32569, 33301, 34471, 35911, 36209, 39373, 40099, 41411, 41659, 43633, 43717, 45139, 47743, 51241, 51257, 55987, 56359, 57991, 58237, 58363, 59747, 62687, 64301, 67289, 69151, 69317, 70459, 71059, 71671, 73061, 80489, 81173, 82051, 82657, 84307, 85333, 87517, 101027, 117307, 119677, 125899, 136711, 136849, 152389, 156421, 160253, 163171, 174907, 190543, 195319, 195497, 208631, 214021, 214133, 216751, 224299, 224911, 226571, 231901, 233113, 235057, 239417, 241259, 241823, 254083, 293989, 314933, 316891, 322249, 323951, 349477, 370061, 387109, 393331, 398477, 440527, 454247, 464843, 585443, 624259, 628189, 634273, 691399, 753947, 841189, 843331, 852641, 907583, 987697, 1032107, 1048919, 1064281, 1126847, 1221167, 1310633, 1536221, 1590917, 1726993, 1938983, 2137687, 2215159, 2541439, 2895881, 3177149, 3439201, 3504689, 3996763, 4167413, 4251703, 4598921, 4690667, 5086087, 5184323, 5336563, 5433089, 5564003, 6330881, 7523531, 7586543, 7725709, 7969729, 8970263, 10367897, 11328017, 12024641, 13122817, 14697373, 15009523, 16186039, 16755803, 27505433, 27989677]


#N = 32
#J = 100

#N = 16
#J = 50

N = 32
J = 500

def get_divider(n):
    max_check = int(math.sqrt(n))
    
    for i in prime_list:
        if i > max_check:
            return None
        if n % i == 0:
            return i
        
def check_str(s):
    ret = []
    for b in range(2,11):
        n = 0
        m = 1
        for c in s:
            if c == '1':
                n += m
            m *= b
        div = get_divider(n)
        if not div:
            return None, None
        ret.append(str(div))
    return s[::-1], ret

print >> res_file, 'Case #1:'

for s in itertools.product(['0', '1'], repeat=N-2):
    n = '1' + ''.join(s) + '1'
    res, div = check_str(n)
    if res:
        print >> res_file, '%s %s' % (res, ' '.join(div))
        J -= 1
        if J == 0:
            break
            
    

#T = int(data[0])
#for i in range(T):
#    print >> res_file, "Case #%s: %s" % (i+1, compute_sleep(int(data[i+1])))
    
res_file.close()