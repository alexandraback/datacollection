class Cell:
    def __init__(self, row, col, mined, clicked):
        self.row = row
        self.col = col
        self.mined = mined
        self.clicked = False
        self.first = clicked
        self.read = False
        self.down = True
        self.right = True

    def get_symbol(self):
        if self.first:
            return "c"
        elif self.mined:
            return "*"
        else:
            return "."

    def mark_as_read(self):
        self.read = True

    def is_read(self):
        return self.read


class Matrix:
    map = []

    def __init__(self, rows, cols, mine):
        self.num_rows = rows
        self.num_cols = cols
        self.max_mine = mine
        self.current_mine = 0

        self.map = self.init_map()

    def init_map(self):
        cols = []
        rows = []
        for i in range(0, self.num_cols):
            for j in range(0, self.num_rows):
                cols.append(None)
            rows.append(cols)
            cols = []
        return rows

    def do_print(self):
        string = ""
        for i in range(0, self.num_rows):
            for j in range(0, self.num_cols):
                cell = self.map[j][i]
                if cell is None:
                    string += "_"
                else:
                    string += cell.get_symbol()
            string += "\n"
        return string

    def add_cell(self, cell):
        self.map[cell.col - 1][cell.row - 1] = cell

    def get_cell(self, row, col):
        try:
            return self.map[col - 1][row - 1]
        except IndexError:
            return None


    def is_possible(self):
        if self.max_mine == self.current_mine:
            if self.check_possible():
                return True
        return False

    def check_possible(self):
        total_free = self.num_cols * self.num_rows - self.max_mine
        total_view = 0
        queue = [self.get_cell(self.num_rows, self.num_cols)]
        while len(queue) != 0:
            current_cell = queue.pop()
            if not current_cell.clicked:
                current_cell.clicked = True
                queue += self.get_cell_around(current_cell)
                total_view += 1
        return total_view == total_free

    def get_cell_around(self, cell):
        around = []
        new_cell = self.get_cell(cell.row + 1, cell.col)
        if new_cell is not None and not new_cell.clicked:
            around.append(new_cell)
        new_cell = self.get_cell(cell.row + 1, cell.col+1)
        if new_cell is not None and not new_cell.clicked:
            around.append(new_cell)
        new_cell = self.get_cell(cell.row, cell.col+1)
        if new_cell is not None and not new_cell.clicked:
            around.append(new_cell)
        new_cell = self.get_cell(cell.row -1, cell.col+1)
        if new_cell is not None and not new_cell.clicked:
            around.append(new_cell)
        new_cell = self.get_cell(cell.row -1, cell.col)
        if new_cell is not None and not new_cell.clicked:
            around.append(new_cell)
        new_cell = self.get_cell(cell.row - 1, cell.col-1)
        if new_cell is not None and not new_cell.clicked:
            around.append(new_cell)
        new_cell = self.get_cell(cell.row, cell.col-1)
        if new_cell is not None and not new_cell.clicked:
            around.append(new_cell)
        new_cell = self.get_cell(cell.row + 1, cell.col -1)
        if new_cell is not None and not new_cell.clicked:
            around.append(new_cell)

        for new_cell in around:
            if new_cell.mined:
                return[]


        return around


    def create_cell(self, row, col):
        existing_cell = self.get_cell(row, col)

        if existing_cell is None:
            if row == self.num_rows and col == self.num_cols:
                new_cell = Cell(row, col, False, True)
            elif self.can_be_mine(row, col) and self.current_mine != self.max_mine:
                self.current_mine += 1
                new_cell = Cell(row, col, True, False)
            else:
                new_cell = Cell(row, col, False, False)
            return new_cell
        return None

    def can_be_mine(self, row, col):
        if self.max_mine == (self.num_rows * self.num_cols) - 1 and not (col == self.num_cols and row == self.num_rows):
            return True
        elif (self.num_rows == 3 and self.num_cols == 5 or self.num_rows == 5 and self.num_cols == 3) and self.max_mine == 6:
            if self.num_cols > self.num_rows:
                if col == 1 or col == 2:
                    return True
            else:
                if row == 1 or row == 2:
                    return True
            return False
        elif row + 1 == self.num_rows and col == self.num_cols:
            return False
        elif col + 1 == self.num_cols and row == self.num_rows:
            return False
        elif col + 1 == self.num_cols and row + 1 == self.num_rows:
            return False
        elif col == self.num_cols and row == self.num_rows:
            return False
        elif self.current_mine == self.max_mine - 1 and (row == self.num_rows-1 or col == self.num_cols-1):
            return False
        else:
            if self.current_mine == self.max_mine - 1:
                cell_row = self.get_cell(row-1, col)
                cell_col = self.get_cell(row, col-1)
                if cell_col is not None and not cell_col.mined:
                    return False
                if cell_row is not None and not cell_row.mined:
                    return False
            return True


class Main:
    R = 0
    C = 0

    def __init__(self):
        pass

    def execute(self):
        f = open("/Users/vchoubard/Downloads/C-large.in", "r")
        output = open("/Users/vchoubard/Downloads/output2.txt", "w")

        # T = 2
        T = int(f.readline()) + 1

        for caseNum in range(1, T):
            line = f.readline()
            # line = "5 2 1"
            # line = "5 6 6"
            Main.R, Main.C, M = map(int, line.split(" "))
            self.matrix = Matrix(self.R, self.C, M)

            self.travel()


            output.write("Case #" + str(caseNum) + ": \n")
            # print "Case #" + str(caseNum) + ": "
            # print self.matrix.do_print()
            if self.matrix.is_possible():
                # print self.matrix.do_print()
                output.write(self.matrix.do_print())
            else:
                # print "Impossible\n"
                output.write("Impossible\n")
                # output.write("miss: " + str(M - self.matrix.current_mine) + "\n")
                # output.write(self.matrix.do_print())

        f.close()
        output.close()


    def add_row(self, cell):
        row = cell.row + 1
        while row <= Main.R:
            new_cell = self.matrix.create_cell(row, cell.col)
            if new_cell is not None:
                self.matrix.add_cell(new_cell)
                row += 1

    def add_col(self, cell):
        col = cell.col + 1
        while col <= Main.C:
            new_cell = self.matrix.create_cell(cell.row, col)
            if new_cell is not None:
                self.matrix.add_cell(new_cell)
                col += 1

    def travel(self):
        init_cell = self.matrix.create_cell(1, 1)
        self.matrix.add_cell(init_cell)
        queue = [init_cell]
        while len(queue) != 0:
            cell = queue.pop()
            if not cell.is_read():
                if Main.C <= Main.R:
                    self.add_col(cell)
                    self.add_row(cell)
                else:
                    self.add_row(cell)
                    self.add_col(cell)

                if len(queue) == 0:
                    init_cell = None
                    if Main.C < Main.R:
                        if cell.row + 1 <= self.matrix.num_rows and cell.row + 1 <= self.matrix.num_cols:
                            init_cell = self.matrix.create_cell(cell.row + 1, cell.row + 1)
                    else:
                        if cell.col + 1 <= self.matrix.num_cols and cell.col + 1 <= self.matrix.num_rows:
                            init_cell = self.matrix.create_cell(cell.col + 1, cell.col + 1)
                    if init_cell:
                        self.matrix.add_cell(init_cell)
                        # print self.matrix.do_print()
                        queue.insert(0, init_cell)

                cell.mark_as_read()


main = Main()
main.execute()