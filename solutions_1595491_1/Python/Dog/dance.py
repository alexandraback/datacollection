from sys import argv
import re

class Score(object):
    def __init__(self, value):
        self.value = value

    def possible_triplets_for_best(self, best):
        m = []
        for b in range(best, 11):
            m.extend(list(self._possible_triplets_for_best(b)))
        return m                
                
    def _possible_triplets_for_best(self, best):        
        for delta in ((0, 0, 0)
                    , (0, 0, -1)
                    , (0, -1, -1)
                    , (0, 0, -2)
                    , (0, -1, -2)
                    , (0, -2, -2)):
            triplet = tuple(max(best + d, 0) for d in delta)
            if sum(triplet) == self.value:
                yield (-2 in delta)

def process_line(s, p, g):
    surprises = int(s)
    best = int(p)
    matches = 0
    for score in map(int, g.split(' ')):
        x = Score(score).possible_triplets_for_best(best)
        if False in x:
            matches += 1
        elif True in x and surprises > 0:
            matches += 1
            surprises -= 1
    return matches               
    
def process_imput(input_string):
    for (i, line) in list(enumerate(input_string.split('\n')))[1:]:
        for m in re.findall('^\d+ (\d+) (\d+) (.*)$', line, re.M):
            yield 'Case #%s: %s' % (i, process_line(*m))


if __name__ == '__main__':
    with open(argv[1]) as input, open(argv[1] + '.out', 'w') as output:
        print >> output, '\n'.join(process_imput(input.read()))
