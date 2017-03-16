#! /usr/bin/env python
import template


class Chest(object):
    def open(self):
        self.solver.keys.remove(self.t)
        self.solver.keys += self.keys
        self.opened = True
        self.solver.solution.append(self.id)

    def close(self):
        self.solver.keys.append(self.t)
        for key in self.keys:
            self.solver.keys.remove(key)
        self.opened = False
        self.solver.solution.remove(self.id)


class App(template.Application):
    def available_chests(self):
        for chest in self.chests:
            if not chest.opened:
                if chest.t in self.keys:
                    yield chest

    def locked_keys(self):
        keys = []
        for chest in self.chests:
            if not chest.opened:
                keys += chest.keys
        return keys

    def done(self):
        return all([c.opened for c in self.chests])

    def open_chests(self):
        for chest in self.available_chests():
            chest.open()
            if chest.t in self.locked_keys():
                if self.open_chests():
                    return True
                chest.close()
            else:
                self.open_chests()
        return self.done()

    def solve(self):
        self.seen = set([])
        num_keys, num_chests = self.ints_line
        self.keys = self.ints_line

        self.chests = []
        self.solution = []

        all_keys = [] + self.keys
        needed = []

        for i in range(num_chests):
            line = self.ints_line
            t, k = line[:2]
            keys = line[2:]
            c = Chest()
            c.solver = self
            c.keys = keys
            c.opened = False
            c.t = t
            c.id = i + 1
            all_keys += c.keys
            needed.append(c.t)
            self.chests.append(c)

        for k in needed:
            if not k in all_keys:
                return "IMPOSSIBLE"
            all_keys.remove(k)

        if self.open_chests():
            return ' '.join(map(str, self.solution))
        else:
            return "IMPOSSIBLE"


if __name__ == '__main__':
    App()
