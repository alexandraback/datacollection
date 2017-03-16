import sys

class GetOutOfLoop(Exception):
    pass

def func(input_str, all=all, str=str):
    char_array = list(input_str)
    index = len(input_str)-1
    flips = 0
    while True:
        for char in char_array:
            if char == "-":
                break
        else:
            return flips
        cur_char = char_array[index]
        while cur_char == "+":
            index -= 1
            cur_char = char_array[index]
        else:
            if char_array[0] == "-":
                char_array = flip(char_array[:index+1])
            else:
                temp_index = index - 1
                while char_array[temp_index] != "+":
                    temp_index -= 1
                char_array = flip(char_array[:temp_index+1]) + char_array[temp_index+1:]
            flips += 1

def flip(cake_chrs):
    new_chars = []
    for char in reversed(cake_chrs):
        if char == "+":
            new_chars.append('-')
        else:
            new_chars.append('+')
    return new_chars

def format_output(case_num, val):
    return ("Case #{case_num}: {val}\n".format(case_num=case_num, val=val))

def parse_input(io):
    # Dump first line
    io.readline()

    while True:
        try:
            foo = io.readline()
            if not foo: 
                break
        except Exception as e:
            print(e)
            io.close()
            break
        else:
            try:
                yield foo.strip()
            except ValueError as e:
                print(e)
                break

def run(io):
    all_output = []
    for index, line in enumerate(parse_input(io)):
        val = func(line)
        output = format_output(index+1, val)
        all_output.append(output)
    return ''.join(all_output).strip()

def main():
    all_output = run(open(sys.argv[1], 'r'))
    print all_output,

if __name__ == "__main__":
    main()
