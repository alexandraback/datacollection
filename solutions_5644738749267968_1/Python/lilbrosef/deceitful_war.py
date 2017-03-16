import sys
import bisect


class Base(object):
    def __init__(self, blocks):
        self.blocks = sorted(blocks)
        self.score = 0


class Ken(Base):
    def choose(self, naomi_block):
        idx = bisect.bisect_right(self.blocks, naomi_block) % len(self.blocks)
        return self.blocks.pop(idx)


class DumbNaomi(Base):
    def choose(self, ken):
        return self.blocks.pop(0)


class DeceitfulNaomi(Base):
    def choose(self, ken):
        if self.blocks[0] < ken.blocks[0]:
            self.blocks.pop(0)
            return ken.blocks[-1] - 1e-7
        else:
            self.blocks.pop(0)
            return ken.blocks[-1] + 1e-7


def play_round(ken, naomi):
    naomi_block = naomi.choose(ken)
    ken_block = ken.choose(naomi_block)
    if naomi_block > ken_block:
        naomi.score += 1
    else:
        ken.score += 1


def main(filename):
    with open(filename) as fd:
        num_tests = int(fd.readline())
        for i in xrange(num_tests):
            n = int(fd.readline())
            naomi_blocks = [float(x) for x in fd.readline().split()][:n]
            ken_blocks = [float(x) for x in fd.readline().split()][:n]

            ken1, ken2 = Ken(ken_blocks), Ken(ken_blocks)
            naomi1 = DumbNaomi(naomi_blocks)
            naomi2 = DeceitfulNaomi(naomi_blocks)

            for _ in range(n):
                play_round(ken1, naomi1)
                play_round(ken2, naomi2)
            print 'Case #{0}: {1} {2}'.format(
                i + 1, naomi2.score, naomi1.score)


if __name__ == '__main__':
    main(sys.argv[1])
