class Seq:
    def __init__(self, seq, g=0):
        result = ['1']
        for c in seq:
            if result[-1] == c:
                continue
            else:
                result.append(c)
        self.seq = result[1:]
        self.g = g
        self.h = abs(self)
        self.f = self.g + self.h
    def __eq__(self, rhs):
        if isinstance(rhs, Seq):
            return self.seq == result.seq
        return len(self.seq) == 1 and self.seq[0] == rhs

    def __abs__(self):
        result = 2* self.seq.count('-')
        if self.seq[0] == '-':
            result -= 1
        return result

    def __lt__(self, rhs):
        return self.f < rhs.f

    def __gt__(self, rhs):
        return self.f > rhs.f

    def __le__(self, rhs):
        return self.f <= rhs.f

    def __ge__(self, rhs):
        return self.f >= rhs.f

    def __len__(self):
        return len(self.seq)

    def __str__(self):
        return ''.join(self.seq)

    def flip(self, N):
        seq1 = ['+' if c == '-' else '-' for c in self.seq[:N]]
        seq2 = self.seq[N:]
        if seq2:
            if seq1[-1] == seq2[0]:
                seq1.pop()
        return Seq(seq1 + seq2, g = self.g+1)

from heapq import heappush as push, heappop as pop

def solve(seq):
    visited = []
    queue = [seq]
    guess = seq.h
    return guess
    while True:
        seq = pop(queue)
        if seq == '+':
            return seq.g, guess
        for i in xrange(len(seq)):
            push(queue, seq.flip(i+1))
def main():
    T = int(raw_input())
    for i in xrange(1, T+1):
        seq = Seq(raw_input())
        print 'Case #%d:' % i, solve(seq)

main()
