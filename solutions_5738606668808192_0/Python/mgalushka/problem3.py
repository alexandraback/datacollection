from sets import Set

def int2base(x, base):
    L = len(x)
    it = L-1
    ttl = 0
    while it >= 0:
        digit = int(x[it])
        ttl += digit*pow(base, L-it-1)
        it -= 1
    return ttl

def check(number, divs):
    divisors = map(lambda a: int(a), divs.split(' '))
    for mod in range(2, 11):
        D = divisors[mod - 2]
        target_number = int2base(number, mod)
        reminder = target_number % D
        if reminder != 0:
            print('Breaks: int2base({0}, {1}) = {2} div {3} = {4}'.format(number, mod, target_number, D, reminder))
            return False
    return True

def main():
    const_reminders = '3 2 3 2 7 2 3 2 3'
    all_coins = Set()
    with open('/Users/mgalushka/google_code_jam/output3_small.out', 'w') as out:
        out.write('Case #1:\n')
        total = 0
        for A1 in range(1, 7):
            for B1 in range(A1+1, 8):
                for A2 in range(1, 7):
                    for B2 in range(A2+1, 8):
                        current = list('0000000000000000')
                        current[0] = '1'
                        current[15] = '1'
                        current[2*A1] = '1'
                        current[2*B1] = '1'
                        current[2*A2-1] = '1'
                        current[2*B2-1] = '1'
                        jamcoin = "".join(current)
                        if jamcoin in all_coins:
                            print('Error: repeated coin: {0}'.format(jamcoin))
                        all_coins.add(jamcoin)
                        print("{0} {1}".format(jamcoin, const_reminders))
                        check(jamcoin, const_reminders)
                        out.write("{0} {1}\n".format(jamcoin, const_reminders))
                        total += 1
                        if total == 50:
                            return

if __name__ == "__main__":
    main()