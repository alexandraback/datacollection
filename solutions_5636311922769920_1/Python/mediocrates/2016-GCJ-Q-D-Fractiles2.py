# If we check the ith tile in the complexity C artwork, where i has a base K expansion of e.g.
#   abcde, then if any of the ath, bth, cth, dth, or eth tiles in the original artwork were G,
#   then the ith tile of the complexity C artwork will also be G.
#
# Thus in order to know for sure whether one G tile is present in the artwork, we just need to check
#   S tiles, where the digits of the base K expansions of the index of the S tiles contain each of
#   1, 2, ..., K.
#
# We will be able to check S*C tiles, so a sufficient (and probably necessary) condition for us to
#   know for sure whether one G tile is present in the artwork is that S*C >= K.


def base10_from_list(numlist, b):
    retVal = 0
    for digit in numlist:
        retVal *= b
        retVal += digit
    return retVal


def main():
    input_filename = 'input.txt'
    output_filename = 'output.txt'
    open(output_filename, 'wb').close()
    with open(input_filename, 'r+b') as f:
        with open(output_filename, 'r+b') as g:
            T = int(f.readline().strip())
            for i in range(1, T+1):
                K, C, S = map(int, f.readline().strip().split())
                if S*C < K:
                    print "Case #%d: IMPOSSIBLE" % i
                    g.write("Case #%d: IMPOSSIBLE\n" % i)
                    continue
                else:
                    digits = range(0, K)
                    tiles_to_check = []
                    if C <= K:
                        # Everything except for possibly an end piece
                        for j in range(K/C):
                            tiles_to_check.append(1 + base10_from_list(digits[C*j:C*(j+1)], K))
                        if K % C != 0:
                            tiles_to_check.append(1 + base10_from_list((K % C)*[0] + digits[-(K % C):], K))
                    else:
                        tiles_to_check.append(1 + base10_from_list(digits, K))
                    print "Case #%d: %s" % (i, ' '.join(map(str, tiles_to_check)))
                    g.write("Case #%d: %s\n" % (i, ' '.join(map(str, tiles_to_check))))


if __name__ == '__main__':
    main()