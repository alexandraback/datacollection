import sys, itertools

def pad(string, pad, count):
    if len(string) < count:
        return (pad * (count - len(string))) + string 
    return string

def binary_iter(count):
    i = 0
    while i < 2 ** count:
        yield pad("{0:b}".format(i), "0", count)
        i += 1

def clean_iter(cleans, limit):
    index = len(cleans) - 1
    limit = str(limit) * len(cleans)
    while not ''.join(cleans) == limit:
        d = int(cleans[index])

def main():
    case = 0
    for line in sys.stdin:
        if case == 0:
            case += 1
            continue

        num_tiles, comp, clean = map(int, line.split(' '))
        
        output = "Case #%d: " % case
        case += 1

        if comp * clean < num_tiles:
            output += "IMPOSSIBLE"
            print output

            continue

        

        total_tiles = num_tiles ** comp
        # print "total:", total_tiles

        tiles = []
        tile = 0
        coeff = 0

        for _ in xrange(clean):

            for c in xrange(0, comp):

                # print "coeff:", coeff
                
                # while tile < total_tiles:
                # print coeff, "*", num_tiles, "^", c
                if tile + coeff * (num_tiles ** c) >= total_tiles:
                    break
                tile += coeff * (num_tiles ** c)
                coeff += 1
                c += 1

            # print "curr tile", tile                

            # print tile, "<", total_tiles

            if tile < total_tiles and tile + 1 not in tiles:
                tiles.append(tile + 1)
                # print tile + 1
            tile = 0



        output += ' '.join(map(str, tiles))
        print output



        

class Sequence:

    def __init__(self):
        self.seqs = []

    def add(self, seq):
        self.seqs.append(seq)

    def filter(self, indices):
        result = []
        for seq in self.seqs:
            if all(seq[i] == 'L' for i in indices):
                result.append(seq)
        return result

if __name__ == '__main__':
    main()