lines = raw_input()
for question_index in xrange(1, int(lines) + 1):
    pancake_stack = raw_input()
    temp = pancake_stack[0]
    count = 0
    for sign in pancake_stack:
        if not sign == temp:
            count += 1
            temp = sign
    if pancake_stack[len(pancake_stack) - 1] == '+':
        print "Case #{}: {}".format(question_index, count)
    else:
        print "Case #{}: {}".format(question_index, count + 1)
