import sys

bit = {}


def check_bit(new_bit):
    if new_bit in bit:
        return bit[new_bit]
    for i in new_bit:
        seen = {}
        immediate = None
        if i in seen and immediate and immediate != i:
            bit[new_bit] = False
            return False
        seen[i] = True
        immediate = i
    bit[new_bit] = True
    return True


def is_valid(seq1, new_bit, seq2):
    # print "is_valid", seq
    #print seq1, seq2
    if seq1 and seq2 and seq1[-1][-1] == seq2[0][0]:
        k = set(new_bit)
        v = k.pop()
        if len(k) == 0 and v == seq1[-1]:
            return True
        return False
    else:
        cb = check_bit(new_bit)
        if not cb:
            return False
        condition = False
        if seq1 and seq1[-1][-1] == new_bit[0] and len(new_bit) == 1:
            return True
        if seq2 and seq2[0][0] == new_bit[0] and len(new_bit) == 1:
            return True
        if not seq1 or seq1[-1][-1] == new_bit[0]:
            condition = True
        if condition and (not seq2 or new_bit[-1] == seq2[0][0]):
            return True
        else:
            lent = 0
            k = set(new_bit)
            seq1_joined = set(''.join(seq1))
            seq2_joined = set(''.join(seq2))
            lent += len(seq1_joined.intersection(k))
            lent += len(seq2_joined.intersection(k))
            #print lent, seq1, new_bit, seq2
            return lent == 0


def get_valids(bits_seq, new_bit):
    ret = []
    new_pos_count = len(bits_seq) + 1
    for i in xrange(new_pos_count):
        if is_valid(bits_seq[0:i], new_bit, bits_seq[i:]):
            new_seq = bits_seq[0:i] + [new_bit] + bits_seq[i:]
            ret.append(new_seq)
    # print ret
    return ret


def solve(bits):
    N = len(bits)
    valid = [0] * (N + 1)
    for i in xrange(N + 1):
        valid[i] = []
    for i in xrange(N):
        # print "Got herre"
        if i > 0:
            for bit in valid[i]:
                new_valids = get_valids(bit, bits[i])
                # print "new_valids", new_valids
                if new_valids:
                    valid[i + 1].extend(new_valids)
        else:
            valid[i + 1] = [[bits[i]]]
    ret = len(valid[N])
    return "%s" % (ret % 1000000007)

if __name__ == "__main__":
    output_file = open("%s.%s" % (sys.argv[1].split(".")[0], "out"), "w")
    file_name = sys.argv[1]
    input_file = open(file_name)
    case_count = int(input_file.readline())
    for i in xrange(case_count):
        specs = input_file.readline()
        sequence = input_file.readline().strip().split(" ")
        result = solve(sequence)
        output_file.write("Case #%s: %s\n" % (i + 1, result))
    output_file.close()
    input_file.close()
    print "Done!"
