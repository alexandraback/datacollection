chars = ['-', '+']


def flip(stack, count):
    if '-' not in stack:
        return count
    if '+' not in stack:
        return count + 1
    first_type = chars.index(stack[0])
    swap = stack.index(chars[1 - first_type])
    stack = stack[:swap][::-1].replace('+', '0').replace('-', '+').replace('0', '-') + stack[swap+1:]
    return flip(stack, count + 1)


file = open('B-large.in', 'r')
out_file = open('output_file.txt', 'w')
amount = file.readline()
for i in range(int(amount)):
    stack_in = file.readline().strip()
    val = flip(stack_in, 0)
    out_file.write('Case #' + str(i+1) + ': ' + str(val) + '\n')
file.close()
out_file.close()
