#!/usr/bin/env python
import argparse
import itertools


def fractilize(seq, C):
    K = len(seq)
    prev_seq = seq
    new_seq = list(seq)
    for i in range(C - 1):
        new_seq = []
        for c in prev_seq:
            if c == 'G':
                new_seq.extend(['G'] * K)
            else:
                new_seq.extend(seq)
        prev_seq = new_seq
    return new_seq


def determine_key_tiles_dumb(sequences):
    no_gold = sequences.pop(0)
    num_lead = []
    for i in range(len(no_gold)):
        num_lead.append(sum(seq[i] == 'L' for seq in sequences))
    sorted_indices = [i[0] for i in sorted(enumerate(num_lead), key=lambda x:x[1])]

    result = []
    lead_seqs = sequences
    for i in sorted_indices:
        result.append(i)
        if all(seq[i] == 'G' for seq in lead_seqs):
            break
        lead_seqs = [seq for seq in lead_seqs if seq[i] == 'L']

    return result


def determine_key_tiles(K, C):
    factor_space = list(range(K))
    indices = []
    while len(factor_space) > 0:
        factors = factor_space[:C]
        factor_space = factor_space[C:]
        if len(factors) < C:
            factors += [0] * C
            factors = factors[:C]
        index = index_from_factors(factors, K)
        indices.append(index)
    return sorted(indices)


def index_from_factors(factors, K):
    index = 0
    for dim, factor in enumerate(factors):
        index += factor * (K ** dim)
    return index


def main(infile, outfile):
    with open(infile, 'r') as input, open(outfile, 'w') as out:
        num_cases = int(input.readline())
        for case in range(1, num_cases+1):
            out.write('Case #{}: '.format(case))

            K, C, S = (int(x) for x in input.readline().rstrip().split())
            indices = determine_key_tiles(K, C)
            if len(indices) > S:
                out.write('IMPOSSIBLE\n')
            else:
                out.write(' '.join([str(i + 1) for i in indices]))
                out.write('\n')
#            orig_perms = itertools.product(['L', 'G'], repeat=K)
#            fractals = [fractilize(perm, C) for perm in orig_perms]
#            print(fractals)
#            check_indices = determine_key_tiles_dumb(fractals)
#            if len(check_indices) > S:
#                out.write('IMPOSSIBLE\n')
#            else:
#                out.write(' '.join([str(i + 1) for i in check_indices]))
#                out.write('\n')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(
        description="codejam qual D")
    parser.add_argument('-i', '--input', type=str,
                        help='Input file')
    parser.add_argument('-o', '--output', type=str,
                        help='Output file')
    args = parser.parse_args()
    main(args.input, args.output)
