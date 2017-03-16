import itertools


def verify_jamcoin(outstr):
    data = outstr.strip().split()
    jc = data[0]
    divisors = map(int, data[1:])
    for i, d in enumerate(divisors):
        print '%10s %10d %10d %10d' % (jc, int(jc, i+2), d, int(jc, i+2) % d)
        if int(jc, i+2) % d != 0:
            return False
    return True


def main():
    retStr = ''
    input_filename = 'input.txt'
    output_filename = 'output.txt'
    open(output_filename, 'wb').close()
    with open(input_filename, 'r+b') as f:
        with open(output_filename, 'r+b') as g:
            T = int(f.readline().strip())  # T == 1
            N, J = map(int, f.readline().strip().split())
            test_primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]
            jamcoins = []
            for possible_jam in itertools.product("01", repeat=N-2):
                pjc = '1' + ''.join(possible_jam) + '1'
                divisors = []
                is_easy_jamcoin = True
                for base in range(2, 11):
                    num = int(pjc, base)
                    has_small_divisors = False
                    for p in test_primes:
                        if num % p == 0:
                            has_small_divisors = True
                            divisors.append(p)
                            break
                    if not has_small_divisors:
                        is_easy_jamcoin = False
                        break
                if is_easy_jamcoin:
                    jamcoins.append(tuple([pjc] + divisors))
                if len(jamcoins) >= J:
                    break

            print "Case #1:"
            retStr += 'Case #1:\n'
            for jc in jamcoins:
                print ' '.join(map(str, jc))
                retStr += ' '.join(map(str, jc))
                retStr += '\n'
            print len(jamcoins)
            g.write(retStr)
    return retStr

if __name__ == '__main__':
    retStr = main()
