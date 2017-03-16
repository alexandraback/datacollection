import sys

class GetOutOfLoop(Exception):
    pass

def func(orig_tile_num ,complexity, viewable_num):
    if viewable_num >= orig_tile_num:
        return [str(num) for num in range(1,viewable_num+1)]

def format_output(case_num, val):
    return ("Case #{case_num}: {val}\n".format(case_num=case_num, val=val))

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
        output = format_output(index+1, ' '.join(val) if val else "IMPOSSIBLE")
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
