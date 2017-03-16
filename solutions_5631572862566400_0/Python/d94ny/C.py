t = int(raw_input())

def create_sittings(bffs, n):
    # create all sequences
    seqs = []
    open_seqs = {}
    seqs_ending_in = {}


    for kid in range(1, n+1):
        seq = []
        seen = {}
        next_kid = kid
        previous_kid = 0
        while next_kid not in seen:
            seq.append(next_kid)
            if next_kid != kid:
                if next_kid in seqs_ending_in:
                    seqs_ending_in[next_kid].append(list(seq))
                else:
                    seqs_ending_in[next_kid] = [list(seq)]

            seen[next_kid] = True
            previous_kid = next_kid
            next_kid = bffs[next_kid - 1]

        # To be a valid sequence the last kid needs to like the first or previous!
        if next_kid == kid or bffs[next_kid - 1] == previous_kid:
            seqs.append(seq)
            if next_kid != kid:
                open_seqs[kid] = True

    return seqs, seqs_ending_in, open_seqs

for i in range(t):
    n = int(raw_input())
    bffs = map(int, raw_input().split(' '))

    # just go from all kids until we reach one we have seen
    seqs, seqs_ending_in, open_seqs =  create_sittings(bffs, n)

    # NOW - go over all good sequences and find a sequence ending in that
    # You can always combine ALL open sequences!! 
    lol = max([len(seq) for seq in seqs])

    best_length = 0
    minimum = 0
    for seq in seqs:
        # if this is not open, no need to check further 
        if seq[0] in open_seqs:
            minimum += len(seq)
            best_extention = 0

            # so we have at least all other open sequences!

            # Find the longest other sequence with only one common thing
            for potential in seqs_ending_in[seq[-1]]:
                if set(potential) & set(seq) == set([seq[-1]]):
                    best_extention = max(best_extention, len(potential) - 1)

            best_length = max(best_length, best_extention)


    print "Case #{0}:".format(i+1),
    print max(lol, minimum + best_length)
