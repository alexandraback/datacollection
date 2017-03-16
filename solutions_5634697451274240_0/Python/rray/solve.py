def find_face(stack, length, face):
    count = 0
    # print "stack:", stack, "length:", length, "face:", face
    for index in xrange(length-1, -1, -1):
        if stack[index] != face:
            break
        count += 1
    # print "returning", count
    return count

def happify(stack, length, state, counter):
    substack_happy = find_face(stack, length, state^1)
    substack_blank = find_face(stack, length, state)

    # print "happy", state^1, substack_happy
    # print "blank", state, substack_blank

    if length == substack_happy:
        return counter
    if length == substack_blank:
        return counter+1

    if substack_happy > substack_blank:
        return happify(stack, length-substack_happy, state, counter)
    elif substack_happy < substack_blank:
        return happify(stack, length-substack_blank, state^1, counter+1)
    return counter

def main():
    t = int(raw_input())
    for i in xrange(t):
        s = map(int, list(raw_input().strip().replace('+', '1').replace('-', '0')))
        print "Case #{}: {}".format(i+1, happify(s, len(s), 0, 0))

if __name__ == '__main__':
    main()
