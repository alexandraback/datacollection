def flip_stack(stack, top_n):
    # Left represents the top of the stack
    """

    :rtype : str
    """
    new_top = ''.join('-' if pancake == '+' else '+' for pancake in stack[top_n-1::-1])
    old_bottom = stack[top_n:]
    assert len(stack) == len(new_top + old_bottom)
    return new_top + old_bottom


def main():
    input_filename = 'input.txt'
    output_filename = 'output.txt'
    open(output_filename, 'wb').close()
    with open(input_filename, 'r+b') as f:
        with open(output_filename, 'r+b') as g:
            T = int(f.readline().strip())
            for i in range(1, T+1):
                stack = f.readline().strip()
                print stack
                flip_count = 0
                pointer = len(stack) - 1
                desired = '-'
                while pointer > 0:
                    while stack[pointer] != desired:
                        pointer -= 1
                        if pointer == -1:
                            break
                    if pointer == -1:
                        break
                    if stack[0] == desired:
                        stack = flip_stack(stack, pointer + 1)
                        flip_count += 1
                        print stack, flip_count
                    else:
                        desired = '+' if desired == '-' else '-'

                pointer = 0
                desired = '+' if stack[0] == '-' else '-'
                while stack != len(stack)*'+':
                    while stack[pointer] != desired:
                        pointer += 1
                        if pointer >= len(stack):
                            flip_count += 1 if stack[0] == '-' else 0
                            break
                    if pointer >= len(stack):
                        break
                    stack = flip_stack(stack, pointer)
                    flip_count += 1
                    print stack, flip_count, "    SECOND"
                    desired = '+' if stack[0] == '-' else '-'
                print "Case #%d: %d" % (i, flip_count)
                print
                g.write("Case #%d: %d\n" % (i, flip_count))


if __name__ == '__main__':
    main()