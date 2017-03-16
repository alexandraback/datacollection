#! /usr/bin/env python
import template


class App(template.Application):
    def solve(self):
        lines = [self.line for _ in range(4)]
        self.line
        for t in ['X', 'O']:
            for line in lines:
                if all([x in [t, 'T'] for x in line]):
                    return "%s won" % t
            for i in range(4):
                if all([x[i] in [t, 'T'] for x in lines]):
                    return "%s won" % t
            if all([lines[i][i] in [t, 'T'] for i in range(4)]):
                return "%s won" % t
            if all([lines[3-i][i] in [t, 'T'] for i in range(4)]):
                return "%s won" % t
        if any(['.' in line for line in lines]):
            return "Game has not completed"
        return "Draw"    


if __name__ == '__main__':
    App()
