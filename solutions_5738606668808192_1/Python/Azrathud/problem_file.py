import sys

class GetOutOfLoop(Exception):
    pass

def func(jam_length, jam_amount):
    jam_generated = 0
    jamcoin_index = 0
    bases = [2,3,4,5,6,7,8,9,10]
    base_len = len(bases)
    jam_coins = [None]*jam_amount
    while jam_generated < jam_amount:
        jam_candidate = gen_jamcoin_candidate(jam_length, jamcoin_index)
        try:
            jam_list = [None] * (base_len+1)
            for index, base in enumerate(bases):
                jamc_int = int(jam_candidate, base)
                prime, div = isprime_time(jamc_int)
                if prime:
                    #print("prime")
                    break
                jam_list[index+1] = str(div)
            else:
                #print(jam_generated)
                jam_list[0] = jam_candidate
                jam_coins[jam_generated] = jam_list
                jam_generated += 1
        except TimeoutError as e:
            pass
            #print(e)
        jamcoin_index += 1

    return '\n'.join([' '.join(line) for line in jam_coins])

def gen_jamcoin_candidate(jam_length, index):
    return "1{0:0{length}b}1".format(index, length=jam_length-2)




def format_output(case_num, val):
    return ("Case #{case_num}:\n{val}\n".format(case_num=case_num, val=val))

def parse_input(io):
    # Dump first line
    io.readline()

    while True:
        try:
            foo = io.readline()
        except:
            io.close()
            break
        else:
            try:
                yield [int(elem) for elem in foo.split(" ")]
            except ValueError as e:
                break

def run(io):
    all_output = []
    for index, line in enumerate(parse_input(io)):
        val = func(*line)
        output = format_output(index+1, val)
        all_output.append(output)
    return ''.join(all_output).strip()

def main():
    all_output = run(open(sys.argv[1], 'r'))
    print all_output,

import time
class TimeoutError(Exception):
    def __init__(self, msg, value):
        super(TimeoutError, self).__init__(self, msg)
        self.value=value

def isprime_time(n, timeout=1):
    """Returns True if n is prime."""
    if n == 3:
        return True, None
    if n % 2 == 0:
        return False, 2
    if n % 3 == 0:
        return False, 3

    i = 5
    w = 2

    t = time.time()
    while i * i <= n:
        if n % i == 0:
            return False, i
        if time.time() - t > timeout:
            raise TimeoutError("%d took to long to determine" % n, n)

        i += w
        w = 6 - w

    return True, None
if __name__ == "__main__":
    main()
