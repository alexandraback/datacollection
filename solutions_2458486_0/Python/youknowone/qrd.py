
import copy
from collections import OrderedDict

class Chest(object):
    def __init__(self, line=None):
        if line is None:
            return
        nums = map(int, line.split(' '))
        self.keytype = nums[0]
        self.keys = nums[2:]
        self.num = None
        assert nums[1] == len(self.keys)

    def __repr__(self):
        return '<Chest({},{},{})>'.format(self.num,self.keytype, self.keys)

    def clone(self):
        new = Chest()
        new.num = self.num
        new.keytype = self.keytype
        new.keys = copy.deepcopy(self.keys)
        return new

    def __deepcopy__(self, memo):
        cls = self.__class__
        new = cls.__new__(cls)
        memo[id(self)] = new
        new.num = self.num
        new.keytype = self.keytype
        new.keys = copy.deepcopy(self.keys, memo)
        return new

class World(object):
    def __init__(self, lines=None):
        if not lines:
            return
        self.keycount, self.chestcount = map(int, lines[0].split(' '))
        self.keys = map(int, lines[1].split(' '))
        self.chests = [Chest(line) for line in lines[2:]]
        assert len(self.keys) == self.keycount
        assert len(self.chests) == self.chestcount
        cdic = {}
        for i, chest in enumerate(self.chests):
            chest.num = i + 1
            try:
                cdic[chest.keytype].append(chest)
            except KeyError:
                cdic[chest.keytype] = [chest]
        self.chestdic = cdic
        for chestlist in cdic.values():
            chestlist.sort(key=lambda chest: -len(chest.keys))
        self.chestdic = OrderedDict(sorted(cdic.iteritems(), 
                                    key=lambda (key, chests): -sum(
                                        map(lambda chest: len(chest.keys), chests)
                                    )))
        self.allkeys = {}
        for keys in [self.keys] + [chest.keys for chest in self.chests]:
            for key in keys:
                try:
                    self.allkeys[key] += 1
                except KeyError:
                    self.allkeys[key] = 1
        self.cleanup()

    def cleanup(self):
        chestkeys = self.chestdic.keys()
        for key in self.keys:
            if key not in chestkeys:
                self.keys.remove(key)
        for chest in self.chests:
            for key in chest.keys:
                if key not in chestkeys:
                    chest.keys.remove(key)
        self.keys.sort()

    def __repr__(self):
        r = '<World(\n'
        r += '  keys: {}\n'.format(self.keys)
        r += '  chests(): {\n'
        for key, chests in self.chestdic.iteritems():
            r += '    {}({}): [\n'.format(key, len(chests))
            for chest in chests:
                r += '      #{} {},\n'.format(chest.num, chest.keys)
            r += '    ],\n'
        r += '})>'
        return r

    def clone(self):
        new = World()
        new.allkeys = copy.deepcopy(self.allkeys)
        new.keys = copy.deepcopy(self.keys)
        new.chestdic = OrderedDict()
        for k, chests in self.chestdic.iteritems():
            new.chestdic[k] = [chest.clone() for chest in chests]
        return new


def solve(world):
    clone = world.clone()
    for ckey, chests in clone.chestdic.iteritems():
        if len(chests) > clone.allkeys[ckey]:
            return False
    return solve_(clone, [])[0]

def solve_(world, depth):
    def depprint(*ts):
        return
        indent = '    ' * len(depth)
        print indent,
        for ti in ts:
            t = str(ti)
            t = t.replace('\n', '\n ' + indent)
            print t,
        print ''
    def okprint(*ts):
        return
        indent = '    ' * len(depth)
        print indent,
        for ti in ts:
            t = str(ti)
            t = t.replace('\n', '\n ' + indent)
            print t,
        print ''
    #print depth
    depprint('------------------------')
    depprint('depth:', depth)
    depprint(world)
    if len(world.chestdic) == 0:
        okprint([])
        okprint(world)
        return [], [world]
    for key in world.keys:
        if key not in world.chestdic:
            continue
        wchests = world.chestdic[key]
        for i in xrange(0, len(wchests)):
            depprint('use {} for ({}/{}) {}'.format(key, i, len(wchests), wchests[i]))
            clone = world.clone()
            chests = clone.chestdic[key]
            chest = chests[i]
            clone.keys.remove(key)
            clone.allkeys[key] -= 1
            clone.keys += chest.keys
            clone.keys.sort()
            del(chests[i])
            if len(clone.chestdic[key]) == 0:
                del(clone.chestdic[key])
            result, worlds = solve_(clone, list(depth) + [chest.num])
            if isinstance(result, list):
                nodes = [chest.num] + result
                okprint(nodes)
                okprint(world)
                return nodes, [world] + worlds
    depprint('==> FAIL')
    return False, []


if __name__ == '__main__':
    count = input()
    for xx in xrange(1, count + 1):
        lines = [raw_input(), raw_input()]
        keycount, chestcount = map(int, lines[0].split(' '))
        lines += [raw_input() for x in xrange(0, chestcount)]
        world = World(lines)
        #print '=================================='
        result = solve(world)
        print 'Case #%d:' % xx,
        if isinstance(result, list):
            print ' '.join(map(str, result))
        else:
            print 'IMPOSSIBLE'
        #print '=================================='