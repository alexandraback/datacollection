import sys

class GetOutOfLoop(Exception):
    pass

def func(number, all=all, str=str):
    lookup = {str(num): False for num in range(10)}
    orig_num = number
    past_values = set()
    cur_mult = 1
    while not all(lookup.values()):
        cur_num = number * cur_mult
        if cur_num in past_values:
            return None
        for char in str(cur_num):
            lookup[char] = True
        cur_mult += 1
        past_values.add(cur_num)
    return cur_num

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
                yield int(foo.strip())
            except ValueError as e:
                break

def run(io):
    all_output = []
    for index, line in enumerate(parse_input(io)):
        val = func(line)
        output = format_output(index+1, val if val is not None else "INSOMNIA")
        all_output.append(output)
    return ''.join(all_output).strip()

def main():
    all_output = run(open(sys.argv[1], 'r'))
    print all_output,

if __name__ == "__main__":
    main()
